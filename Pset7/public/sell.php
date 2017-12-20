<?php

    // configuration
    require("../includes/config.php"); 

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("sell.php", ["title" => "Sell"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["stock_to_sell"]))
        {
            apologize("Enter the stock you wish to sell");
        }
        else
        {
            $stock = $_POST["stock_to_sell"];
            $shares = CS50::query("SELECT shares FROM Holding WHERE user_id = ? AND symbols = ?", $_SESSION["id"], $stock);
            
            if ($shares == false)
            {
		        apologize("Enter a stock symbol of a stock you own");
            }
            else
            {
               
                $stock_data = lookup("$stock");  
                
                $net_sale = $shares[0]["shares"] * $stock_data["price"];
                
                CS50::query("DELETE FROM Holding WHERE user_id = ? AND symbols = ?", $_SESSION["id"], $stock);
	 	        
	 	        CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $net_sale, $_SESSION["id"]);
	 	        
	 	        $type = 'SELL';
    	 	    CS50::query("INSERT INTO history (usr_id, type, symbols, shares, price) VALUES (?, ?, ?, ?, ?)", $_SESSION["id"], $type, $_POST["stock_to_sell"], $_POST["number_to_sell"], $stock["price"]);
	 	        // redirect to portfolio
                redirect("/");
	 	        
            }
            
        }
    }
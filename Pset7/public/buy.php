<?php

    // configuration
    require("../includes/config.php"); 

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("buy.php", ["title" => "Buy"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["stock_to_buy"]))
        {
            apologize("Enter the stock you wish to buy");
        }
        else
        {
            $stock = strtoupper($_POST["stock_to_buy"]);
            
            $number_to_buy = $_POST["number_to_buy"];
            
            if (preg_match("/^\d+$/", $_POST["number_to_buy"]) == false)
            {
                apologize("Enter a valid number of shares.");
            }
            
            $stock_data = lookup("$stock"); 
            if ($stock_data == false)
            {
                apologize("That was an invalid symbol.");
            }
                
            $net_sale = $number_to_buy * $stock_data["price"];
            $cash = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
            if ($cash < $net_sale)
            {
                apologize("You're too poor for that.");
            }
            else
            {
                $user = $_SESSION["id"];
                CS50::query("INSERT INTO Holding (user_id, symbols, shares) VALUES($user, '$stock', $number_to_buy) ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)");    
                
    	 	        
    	 	    CS50::query("UPDATE users SET cash = cash - ? WHERE id = ?", $net_sale, $_SESSION["id"]);
    	 	    $type = 'BUY';
    	 	    CS50::query("INSERT INTO history (usr_id, type, symbols, shares, price) VALUES (?, ?, ?, ?, ?)", $_SESSION["id"], $type, $_POST["stock_to_buy"], $_POST["number_to_buy"], $stock_data["price"]);
    
    	 	    // redirect to portfolio
                redirect("/");
            }
        }
    }
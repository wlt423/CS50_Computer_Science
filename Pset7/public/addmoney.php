<?php

    // configuration
    require("../includes/config.php"); 

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("addmoney.php", ["title" => "Add Money"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["money_added"]))
        {
            apologize("You didn't add any money.");
        }
        else
        {
            $money = $_POST["money_added"];
            
            CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $money, $_SESSION["id"]);
            // redirect to portfolio
            redirect("/");
        }
    }
?>
            
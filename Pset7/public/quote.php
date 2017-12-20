<?php

    // configuration
    require("../includes/config.php"); 
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("stock_submit.php", ["title" => "Stock Lookup"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {

        // lookup stock price
        $stock = lookup($_POST["symbol"]);
        
        if ($stock == false)
        {
            apologize("That was an invalid symbol.");
        }
        else
        {
            render("stock_display.php", ["title" => "Stock Display", "data" => $stock]);
            
            
             
        }
    }    
?>
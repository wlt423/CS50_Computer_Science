<?php

    // configuration
    require("../includes/config.php"); 
    
    $rows = CS50::query("SELECT * FROM Holding WHERE user_id = ?", $_SESSION["id"]);
    $positions = [];
    
    foreach ($rows as $row)
    {
        $stock = lookup($row["symbols"]);
        if ($stock !== false)
        {
            $positions[] = [
                "name" => $stock["name"],
                "price" => $stock["price"],
                "shares" => $row["shares"],
                "symbol" => $row["symbols"]
            ];
        }
    }
    
    $cash = CS50::query("SELECT username, cash FROM users WHERE id = ?", $_SESSION["id"]);
    // render portfolio
    render("portfolio.php", ["positions" => $positions, "title" => "Portfolio", "cash" => $cash]);
    ?>

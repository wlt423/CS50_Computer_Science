<?php
    // configuration
    require("../includes/config.php");  
    
    
    $cash =	CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);	
    
	// new array for history 
    $history = CS50::query("SELECT * FROM history WHERE usr_id = ?", $_SESSION["id"]);
    
    // render history form
    render("history.php", ["title" => "History", "cash" => $cash, "history" => $history]);
   
?>

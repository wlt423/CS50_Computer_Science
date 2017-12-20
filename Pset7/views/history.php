<div>
    foreach ($history as $row)
            {
                print("<tr>");
                print("<td>{$position["symbol"]}  <br>  </td>");
                print("<td> {$position["shares"]}  <br>  </td>");
                print("<td> {$position["price"]}  <br>  </td>");
                $value = $position["price"]*$position["shares"];
                print("<td> $value  <br>  </td>");
                print("</tr>");
            }
</div>
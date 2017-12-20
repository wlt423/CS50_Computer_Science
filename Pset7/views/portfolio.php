<div>
    <table border="1" align="center" cellpadding="10" cellspacing="10">
        <th>Stock              </th>
        <th>  #  Shares</th>
        <th>Price</th>
        <th>Value</th>
        <?php
            
            foreach ($positions as $position)
            {
                print("<tr>");
                print("<td>{$position["symbol"]}  <br>  </td>");
                print("<td> {$position["shares"]}  <br>  </td>");
                print("<td>$".number_format($position["price"], 2)."</td>");
                $value = $position["price"]*$position["shares"];
                print("<td>$".number_format($value, 2)."</td>");
                print("</tr>");
            }
            
            
            
        ?>
        
    </table>
    </p>
    </p>
    <table  align="center" cellpadding="10" cellspacing="10">
    <th>Balance </th>
    <td>$<?=number_format($cash[0]["cash"], 2)?></td>
    </table>
</div>

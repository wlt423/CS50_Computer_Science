<form action="buy.php" method="post">
    <fieldset>
        <div class="form-group">
            <input autocomplete="off" autofocus class="form-control" name="stock_to_buy" placeholder="Stock To Buy" type="text"/>
        </div>
        <div class="form-group">
            <input class="form-control" name="number_to_buy" placeholder="# of Shares" type="integer"/>
        </div>
        <div class="form-group">
            <button class="btn btn-default" type="submit">
                <span aria-hidden="true" class="glyphicon glyphicon-log-in"></span>
                Buy Now!
            </button>
        </div>
    </fieldset>
</form>
<?

include('Mushi.mjs'); //Load the Mushi javascript api



?>

<h1>Current tickets in the system:</h1>

<?


var res = Mushi.getTasks();

?>


<table border=1>
<?
for (i in res){
    var row=res[i];
?>
    <tr>
    <td><?=row.title?></td>
    <td><?=htmlentities(row.description)?></td>
    
    
    </tr>
<?}
?>
</table>

<a href="/" >home</a>


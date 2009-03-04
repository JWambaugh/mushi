<?

include(_config.getValue("scriptDirectory")+'/Mushi.mjs'); //Load the Mushi javascript api

include(_config.getValue("scriptDirectory")+'/JSON.mjs'); //Load the JSON api
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



<h2>Tables in the database:</h2>

<table border="1">

<?
var tables = _db.select("select * from sqlite_master where type='table' order by type, name");



for (i in tables){
?>
	<tr>
	<td><?=tables[i].name?></td><td><?=tables[i].sql?></td>
	</tr>
<?}?>
</table>



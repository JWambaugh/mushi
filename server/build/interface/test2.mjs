




<h2>
Run command test
</h2>
<?

//add a test user
var result = Mushi.runCommand({
     command:"addUser"
    ,firstName:"Jordan"
    ,lastName:"Wambaugh"
    ,email:"jordan@wambaugh.org"
    ,password:"pass"
    });
Mushi.conn.print("<pre>"+debug(result)+"</pre>");

var id = Mushi.db.getInsertRowID();
Mushi.db.exec("delete from user where ROWID = "+id);


//add a role
var result = Mushi.runCommand({
     command:"addRole"
    ,name:"nameOfRole"
    ,description:"this is the description"
    });
Mushi.conn.print("<pre>"+debug(result)+"</pre>");

var id = Mushi.db.getInsertRowID();
Mushi.db.exec("delete from role where ROWID = "+id);


//add a project
var result = Mushi.runCommand({
     command:"addProject"
    ,name:"sample project2"
    ,description:"this is the description"
    });
Mushi.conn.print("<pre>"+debug(result)+"</pre>");

var id = Mushi.db.getInsertRowID();
//Mushi.db.exec("delete from project where ROWID = "+id);




?>

<?=Mushi.db.object2Insert({firstName:"jordan",lastName:"wamabugh"},['firstName','lastName'],"roles")?>
<br>
<?=Mushi.db.object2Update({firstName:"jordan",lastName:"wamabugh"},['firstName','lastName'],"roleId='2'","roles")?>

</body>

<?
with(Mushi){

    //get the task
    var task = runCommand({
        command:"getTask"
        ,taskID:conn.getVar("taskID")
    
    });
    if(und(task.results) && task.results.length>0){
        task = task.results[0];   
    }
    
   var subscribers = db.select("select s.id as subscriptionID, u.id as userId, u.firstName, u.lastName,u.email from taskSubscriber s join user u on u.id=s.subscriberID");    
    

}

?>

<h2>Subscribers to ticket #<?=task.id?></h2>
" <?=task.title?> "

<table border=1>
<?
for(var x=0;x<subscribers.length;x++){
    var subscriber=subscribers[x];?>
    <tr>
    <td>blah</td>
    </tr>

<?}?>



</table>


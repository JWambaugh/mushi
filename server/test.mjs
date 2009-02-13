//print("Running\n");

//var z = {};
//z.foo ="hello";
//print(z);


//conn.print("hello");


print("hello world! wow, this works! Sum of 1+5:"+(1+5));


print("<br>Query string:"+_conn.queryString());
print("<br>URI:" +_conn.URI());

print("value of hmmm: " +_conn.getVar("hmm"));

var res=_db.select("select * from task");
//print("<pre>"+debug(res)+"</pre>");
print("<br>Current tickets in system: ");

_p('<table border=1>');
for (i in res){
    var row=res[i];
    _p('<tr>');
    print("<td>"+row.title+"</td>");
    print("<td>"+htmlentities(row.description)+"</td>");
    
    
    _p('</tr>');
}
_p('</table>');

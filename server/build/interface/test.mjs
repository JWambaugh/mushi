
<head>
<link href="/extjs2.2.1/ext-all.css" rel="stylesheet" type="text/css">
<script type="text/javascript" src="/extjs2.2.1/ext-base.js"></script>
<script type="text/javascript" src="/extjs2.2.1/ext-all-debug.js"></script>

<script>


/**
 * @class Ext.grid.TableGrid
 * @extends Ext.grid.Grid
 * A Grid which creates itself from an existing HTML table element.
 * @constructor
 * @param {String/HTMLElement/Ext.Element} table The table element from which this grid will be created - 
 * The table MUST have some type of size defined for the grid to fill. The container will be 
 * automatically set to position relative if it isn't already.
 * @param {Object} config A config object that sets properties on this grid and has two additional (optional)
 * properties: fields and columns which allow for customizing data fields and columns for this grid.
 * @history
 * 2007-03-01 Original version by Nige "Animal" White
 * 2007-03-10 jvs Slightly refactored to reuse existing classes
 */
Ext.grid.TableGrid = function(table, config) {
  config = config || {};
  Ext.apply(this, config);
  var cf = config.fields || [], ch = config.columns || [];
  table = Ext.get(table);

  var ct = table.insertSibling();

  var fields = [], cols = [];
  var headers = table.query("thead th");
  for (var i = 0, h; h = headers[i]; i++) {
    var text = h.innerHTML;
    var name = 'tcol-'+i;

    fields.push(Ext.applyIf(cf[i] || {}, {
      name: name,
      mapping: 'td:nth('+(i+1)+')/@innerHTML'
    }));

    cols.push(Ext.applyIf(ch[i] || {}, {
      'header': text,
      'dataIndex': name,
      'width': h.offsetWidth,
      'tooltip': h.title,
      'sortable': true
    }));
  }
  var ds  = new Ext.data.Store({
    reader: new Ext.data.XmlReader({
      record:'tbody tr'
    }, fields)
  });

  ds.loadData(table.dom);

  var cm = new Ext.grid.ColumnModel(cols);


  if (config.width || config.height) {
    ct.setSize(config.width || 'auto', config.height || 'auto');
  } else {
    ct.setWidth(table.getWidth());
  }

  if (config.remove !== false) {
    table.remove();
  }

  Ext.applyIf(this, {
    'ds': ds,
    'cm': cm,
    'sm': new Ext.grid.RowSelectionModel(),
    autoHeight: true,
    autoWidth: false
  });
  Ext.grid.TableGrid.superclass.constructor.call(this, ct, {});



};


var panel=new Ext.grid.GridPanel({
	renderTo:'ticketGrid'
	
});
	
Ext.extend(Ext.grid.TableGrid, Ext.grid.GridPanel);
Ext.onReady(function(){
panel.render();
	
	//var grid= new Ext.grid.TableGrid('tickets');
	//grid.render();
});
</script>

</head>
<body>

<img src="/mushiLogo.png" /><br>
<?

Mushi.include(Mushi.config.getValue("scriptDirectory")+'/Mushi.mjs'); //Load the Mushi javascript api

Mushi.include(Mushi.config.getValue("scriptDirectory")+'/JSON.mjs'); //Load the JSON api
?>

<h1>Current tickets in the system:</h1>
<?


var res = Mushi.getTasks();



?>


<div id='ticketGrid'></div>

<table border=1 id="tickets" >
<?
for (i in res){
    var row=res[i];
?>
    <tr>
    <td width='100'><?=row.title?></td>
    <td><?=htmlentities(row.description)?></td>
    
    
    </tr>
<?}
?>
</table>

<a href="/" >home</a>



<h2>Tables in the database:</h2>

<table border="1">

<?
var tables = Mushi.db.select("select * from sqlite_master where type='table' order by type, name");



for (i in tables){
?>
	<tr>
	<td><?=tables[i].name?></td><td><?=tables[i].sql?></td>
	</tr>
<?}?>
</table>


<h2>
Run command test
</h2>
<?
var result = Mushi.runCommand({
    command:"findTask"
    
    });
Mushi.conn.print(debug(result));
?>





</body>


<head>
<link href="/extjs2.2.1/ext-all.css" rel="stylesheet" type="text/css">
<script type="text/javascript" src="/extjs2.2.1/ext-base.js"></script>
<script type="text/javascript" src="/extjs2.2.1/ext-all-debug.js"></script>



</head>
<body>

<img src="/mushiLogo.png" /><br>
<?

Mushi.include(Mushi.config.getValue("scriptDirectory")+'/Mushi.mjs'); //Load the Mushi javascript api

Mushi.include(Mushi.config.getValue("scriptDirectory")+'/JSON.mjs'); //Load the JSON api

var tasks = Mushi.getTasks();

?>
<br>
Tasks in the system: <?=tasks.length?>

<a href='http://google.com'>google</a>




</body>

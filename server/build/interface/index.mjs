
<head>




</head>
<body>

<img src="/mushiLogo.png" /><br>
<?

var tasks = Mushi.getTasks();

?>


<? Mushi.include(Mushi.config.getValue("interfaceDirectory")+'/mainMenu.mjs'); ?>
<br>
Tasks in the system: <?=tasks.length?>






</body>

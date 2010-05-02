<html>
<head>
<link href="/ext-3.0.3/resources/css/ext-all.css" rel="stylesheet" type="text/css">
<script type="text/javascript" src="/ext-3.0.3/ext-base.js"></script>
<script type="text/javascript" src="/ext-3.0.3/ext-all-debug.js"></script>
<script>

<?

//Mushi.include(Mushi.config.getValue("scriptDirectory")+'/Mushi.mjs'); //Load the supplimental Mushi javascript api

?>
Ext.onReady(function(){
    Ext.QuickTips.init();
    // Create HttpProxy instance.  Notice new configuration parameter "api" here instead of load.  However, you can still use
// the "url" paramater -- All CRUD requests will be directed to your single url instead.
var proxy = new Ext.data.HttpProxy({
    method:'POST'
    ,url:'/command'
,listeners: {
            write : function(proxy, action, result, res, rs) {
                store.commitChanges();
            }
        }    
});

proxy.conn.method="POST";
//window.console.log(proxy.conn)
proxy.on("beforeload",function(ob,params){
    //alert('ran');
    proxy.conn.method='POST';
    proxy.api={
        read : {url:'/command',method:'POST'},
        create : {url:'/command',method:'POST'},
        update: {url:'/command',method:'POST'},
        destroy: {url:'/command',method:'POST'}
    }
    window.console.log(proxy.conn)
    params.data='{"command":"getConfig"}';
    delete params.xaction;
    });

proxy.on("beforewrite",function(ob,action,record,params){
    //alert('ran');
    proxy.conn.url='/command';
    proxy.api={
        read : {url:'/command',method:'POST'},
        create : {url:'/command',method:'POST'},
        update: {url:'/command',method:'POST'},
        destroy: {url:'/command',method:'POST'}
    }
    window.console.log(proxy.conn)
    record["command"]="setConfig";
    delete params.xaction;
    });


// Typical JsonReader.  Notice additional meta-data params for defining the core attributes of your json-response
var reader = new Ext.data.JsonReader({
    //totalProperty: 'total',
    successProperty: 'success',
    idProperty: 'key',
    root: 'data'
}, [
    {name:'command',defaultValue:'saveConfig'}
    ,{name: 'key'}
    ,{name: 'value', allowBlank: false}
    ,{name: 'description'}
]);

// The new DataWriter component.
var writer = new Ext.data.JsonWriter({
    encode: true
    ,writeAllFields: true
});

    
// create the data store
    var store = new Ext.data.Store({
        reader:reader
        ,writer:writer
        ,proxy:proxy
       // ,restful:true
        ,autoSave:true
        
    });

    // manually load local data
    store.load();

    // create the Grid
    var grid = new Ext.grid.EditorGridPanel({
        store: store,
        columns: [
            {header: 'Key', width: 200, sortable: true, dataIndex: 'key',renderer:function(value, metaData, record, rowIndex, colIndex, store){return "<span ext:qtip='"+record.get('description')+"'>"+value+"</span>"}}
            ,{header: 'Value', width: 200, sortable: true, dataIndex:'value',renderer:function(value, metaData, record, rowIndex, colIndex, store){return "<span ext:qtip='"+record.get('description')+"'>"+value+"</span>"},editor: new Ext.form.TextField({
                    allowBlank: false
                })}
        ],
        clicksToEdit:1,
        stripeRows: true,
        //autoExpandColumn: 'company',
        height: 350,
        width: 600,
        title: 'Array Grid'
        // config options for stateful behavior
        //stateful: true,
        //stateId: 'grid'        
        ,renderTo:'grid'
    });
});
</script>


</head>
<body>
<img src="/mushiLogo.png" /><br>

<?Mushi.include(Mushi.config.getValue("interfaceDirectory")+'/admin/adminMenu.mjs');?>
Configuration

<div id='grid'>
</div>
</html>
<?

/**
 * Mushi sample plugin
 * keep in mind a new plugin object is instantiated for every request.
 */
Mushi.Plugin.add({
    
    
    //Name of the plugin
    _name:'MyPlugin'
    
    
    /**
     * Always executed when pluggin is loaded. Note this is called every time a plugin object is instantiated. This includes on server initialization and on every command and .mjs request.
     */
    ,_construct:function(){
        //Mushi.log(this._name+' has been loaded!');
    }
    
    /**
     * Called when a command is executed
     * MUST return ret object!
     */
    ,_commandHandler:function(command,ret){
       /* Mushi.log(debug(command));
        Mushi.log(debug(ret));*/
        return ret;
    }
    
    /**
     * called only once, at system startup
     */
    ,_systemInit:function(){
        Mushi.log("MyPLugin initialized.");
    }
    


});
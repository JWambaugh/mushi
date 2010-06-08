<?
Mushi.log("Loading MyPlugin");

Mushi.Plugin.add({
    
    
    //Name of the plugin
    _name:'MyPlugin'
    
    
    /**
     * Always executed when pluggin is loaded.
     */
    ,_construct:function(){
        Mushi.log(this._name+' has been loaded!');
    }
    
    
    ,_commandHandler:function(command,ret){
        Mushi.log(debug(command));
        return ret;
    }
    
    


});
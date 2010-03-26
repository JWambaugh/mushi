<?
(function(command,ret){
    with(Mushi){
		//only do somthing if our command was called
		if(command.command=="addRight"){
        
            //make sure all required params are given
            if(Mushi.und(command.name)==''){
                ret.status='error';
                ret.message='Name not specified when adding a right.';
                return ret;
            }
            
            //make sure there isn't already a right with this name
            var results = Mushi.db.select("select * from right where name = '"+Mushi.escapeQuotes(command.name)+"'");
            if(results.length>0){
                ret.status='error';
                ret.message='A right with the name of '+command.name+' already exists.';
                return ret;
            }
            
        
			Mushi.db.exec(Mushi.db.object2Insert(command,['name','description'],"right"));
			ret.status='success';
		}
		return ret; //always return the ret value.
    }
})



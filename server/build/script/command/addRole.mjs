<?
(function(command,ret){
    with(Mushi){
		//only do somthing if our command was called
		if(command.command=="addRole"){
        
            if(validate.required(command,ret, ['name','projectID'])){
                return ret;
            }
            
            //make sure there isn't already a role with this name
            var results = Mushi.db.select("select * from role where name = '"+Mushi.escapeQuotes(command.name)+"'");
            if(results.length>0){
                ret.status='error';
                ret.message='A role with the name of '+command.name+' already exists.';
                return ret;
            }
        
			Mushi.db.exec(Mushi.db.object2Insert(command,['name','description','projectID'],"role"));
			ret.status='success';
		}
		return ret; //always return the ret value.
    }
})


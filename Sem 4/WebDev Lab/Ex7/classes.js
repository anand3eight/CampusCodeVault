class display{
    constructor(msg){
        this.msg = msg;
    }
    static fun(){
        return "Hello World";
    }
    fun2(){
        return this.msg;
    }

}

let displayObj = new display("Hola");
//console.log(displayObj.addfun())    //Shows Error : TypeError: addObj.addfun is not a function
console.log("Static Function : ", display.fun(), "\nNormal Function : ", displayObj.msg);

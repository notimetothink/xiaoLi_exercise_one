// 适配器模式
package design_patterns.codes;

public class AdapterPattern {
    public static void main(String[] args){
        USB usb = new Adapter();
        usb.Request();
    }
}

class USB{
    public void Request(){
        System.out.println("USB数据线");
    }
}

class Adapter extends USB{
    private TypeC typeC = new TypeC();
    public void Request(){
        typeC.SpecificRequest();
    } 
}

class TypeC{
    public void SpecificRequest(){
        System.out.println("type-c数据线");
    }
}
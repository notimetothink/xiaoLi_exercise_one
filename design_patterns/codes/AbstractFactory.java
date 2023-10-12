package design_patterns.codes;
// 抽象工厂
public class AbstractFactory {
    public static void main(String[] args) {
        Factory factory1 = new Factory1();

        ProductA productA = factory1.createProductA();
        productA.info();

        Factory factory2 = new Factory2();

        ProductB productB = factory2.createProductB();
        productB.info();
    }
}
interface Factory{
    public ProductA createProductA();
    public ProductB createProductB();
}
class Factory1 implements Factory{
    public ProductA createProductA(){
        return new ProductA1();
    }
    public ProductB createProductB(){
        return new ProductB1();
    }
}
class Factory2 implements Factory {

    @Override
    public ProductA createProductA() {
        return new ProductA2();
    }

    @Override
    public ProductB createProductB() {
        return new ProductB2();
    }
}
interface ProductA{
    public void info();
}
interface ProductB{
    public void info();
}
class ProductA1 implements ProductA{
    public void info() {
        System.out.println("产品的信息：A1");
    }
}
class ProductA2 implements ProductA{
    public void info() {
        System.out.println("产品的信息：A2");
    }
}
class ProductB1 implements ProductB{
    public void info() {
        System.out.println("产品的信息：B1");
    }
}
class ProductB2 implements ProductB{
    public void info() {
        System.out.println("产品的信息：B2");
    }
}
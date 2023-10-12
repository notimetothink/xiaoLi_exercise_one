// 生成器模式
package design_patterns.codes;
import java.util.*;

public class BuilderPattern {
    public static void main(String[] args) {
        Director director = new Director();
        Builder builder1 = new Builder1();
        director.Construct(builder1);
        Product product1 = builder1.GetResult();
        product1.show();

        Builder builder2 = new Builder2();
        director.Construct(builder2);
        Product product2 = builder2.GetResult();
        product2.show();
    }
}

class Director{
    public void Construct(Builder builder){
        builder.BuildPart();
    }
}
abstract class Builder{
    public abstract void BuildPart();
    public abstract Product GetResult();
}

class Builder1 extends Builder{
    Product product = new Product();
    public void BuildPart(){
        product.add("A");        
        product.add("B");
    }
    public Product GetResult(){
        return product;
    }
}

class Builder2 extends Builder{
    Product product = new Product();
    public void BuildPart(){
        product.add("C");        
        product.add("D");
        product.add("E");
    }
    public Product GetResult(){
        return product;
    }
}

class Product {
    List<String> parts = new ArrayList<String>();
    public void add(String part){
        parts.add(part);
    }
    public void show(){
        System.out.print("产品的组成：");
        for (String s : parts){
            System.out.print(s + " ");
        }
        System.out.print("\n");
    }
}

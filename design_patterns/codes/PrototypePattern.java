// 原型模式
package design_patterns.codes;
public class PrototypePattern {
    public static void main(String[] args) {
        Product product1 = new Product(2023, 11.4);
        System.out.println(product1.getId() + " " + product1.getPrice());
        Product product2 = (Product)product1.Clone();
        System.out.println(product2.getId() + " " + product2.getPrice() + "123");

    }
}

interface Prototype{
    public Object Clone();
}

class Product implements Prototype{
    private int id;
    private double price;
    public Product() {}

    public Product(int id, double price) {
        this.id = id;
        this.price = price;
    }
    public int getId() {
        return id;
    }

    public double getPrice() {
        return price;
    }
    public Object Clone(){
        Product obj = new Product();
        obj.id = this.id;
        obj.price = this.price;
        return obj;
    }
}
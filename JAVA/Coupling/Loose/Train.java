package Coupling.Loose;

public class Train implements Transport {
    
    @Override
    public void start() {
        System.out.println("Train trip started....");
    }
}

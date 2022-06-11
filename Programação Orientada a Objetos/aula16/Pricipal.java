package aula16;

import java.util.ArrayList;
import java.util.List;

public class Pricipal {

	public static void main(String[] args) {
		
		Carro car = new Carro("EGD-3421", "Sandero");
		Carro car2 = new Carro("TEC-0942", "Civic");
		
		List<Carro> vet = new ArrayList<Carro>();
		
//		vet.add("Gabriel");
//		vet.add("Lucas");
//		vet.add("Carlos");
//		vet.add(10);
//		vet.add(58.88);
		vet.add(car);
		vet.add(car2);
		
		for(Carro carro : vet)
			System.out.println(carro.getPlaca());
		
	}
}

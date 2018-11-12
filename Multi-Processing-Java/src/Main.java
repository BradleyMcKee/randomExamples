import java.util.*;

public class Main {
	public static ArrayList<BufferItems> buffer = new ArrayList<BufferItems>();
	public final static int p = 20, c = 10;
	public static Consumer allCons[] = new Consumer[c];
	
	public static void main (String[] args) {		
		Producer allProds[] = new Producer[p];
		
		Flagger flag = new Flagger();
		
		for (int i = 0; i < p; i++) {
			allProds[i] = new Producer(i + 1);
			allProds[i].start();
		}
		
		while(true) {
			System.out.println(buffer.size());

			if (buffer.size() >= 10000) {
				for (int i = 0; i < buffer.size(); i++)
					System.out.println(buffer.get(i));
				
				System.out.println(buffer.size());
				flag.start();

				for (int i = 0; i < c; i++) {
					allCons[i] = new Consumer(i + 1);
					allCons[i].start();
				}
				break;
			}
		}
					
	}
}

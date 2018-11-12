import java.text.DecimalFormat;

public class Producer extends Thread {
	private final long TIME_TO_WASTE = 40;
	private final long MINIMAL_TIME = 5;
	private int storeID;

	public Producer(int s) {
		this.storeID = s;
	}

	public void run() {
		try {
			do {
				Main.buffer.add(createRecord());
				sleep((long) (Math.random() * TIME_TO_WASTE) + MINIMAL_TIME);
			} while (Main.buffer.size() < 10000);
		} catch (InterruptedException e) {
			System.err.println("Something went wrong");
			System.exit(1);
		}
	}

	public BufferItems createRecord() {
		int DD = (int) (Math.random() * 30) + 1;
		int MM = (int) (Math.random() * 12) + 1;
		int registerNum = (int) (Math.random() * 6) + 1;
		double saleAmount = Math.random() * 999.99 + 0.50;

		return new BufferItems(Integer.toString(DD) + "/" + Integer.toString(MM) + "/16", this.storeID, registerNum,
				Double.parseDouble(new DecimalFormat("##.##").format(saleAmount)));
	}
}

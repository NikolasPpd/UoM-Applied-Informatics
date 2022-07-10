import java.text.SimpleDateFormat;

public class Main {

	public static void main(String[] args) {
		
		//Creation of suspect objects
		Suspect s1 = new Suspect("John Dow", "Sleepy Dog", "Barcelona");
		s1.addNumber("00496955444444");
		s1.addNumber("00496955333333");
		
		Suspect s2 = new Suspect("Danny Rust", "Rusty Knife", "London");
		s2.addNumber("00446999888888");
		
		Suspect s3 = new Suspect("Bob Robson", "Frozen Bear", "Oslo");
		s3.addNumber("00478484777777");
		s3.addNumber("00478484666666");
		s3.addNumber("00478484222222");

		// Added a fourth suspect with one connection to recreate the graph from the example
		Suspect s4 = new Suspect("Gill Bates", "Lizard Man", "Athens");
		s4.addNumber("00306969111111");
		s4.addNumber("00306969555555");

		//Creation of communication objects
		SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy/MM/DD");
		
		Communication[] comms = new Communication[15];
		
		comms[0] = new PhoneCall("00496955444444", "00478484777777", 15, 10, 2021, 127);
		comms[1] = new PhoneCall("00496955444444", "00478484777777", 16, 10, 2021, 240);
		comms[2] = new PhoneCall("00446999888888", "00496955333333", 17, 10, 2021, 52);
		comms[3] = new PhoneCall("00446999888888", "00478484777777", 18, 10, 2021, 180);
		comms[4] = new PhoneCall("00478484666666", "00496955333333", 19, 10, 2021, 305);
		comms[5] = new PhoneCall("00496955444444", "00478484222222", 20, 10, 2021, 247);
		comms[6] = new PhoneCall("00478484222222", "00496955333333", 21, 10, 2021, 32);
		comms[7] = new PhoneCall("00306969111111", "00446999888888", 25, 12, 2021, 24);
		
		comms[8] = new SMS("00496955444444", "00478484777777", 10, 10, 2021, "fancy a drink tonight?");
		comms[9] = new SMS("00496955333333", "00446999888888", 11, 10, 2021, "Nitro Bomb prepared");
		comms[10] = new SMS("00446999888888", "00496955444444", 12, 10, 2021, "flying to Berlin tomorrow");
		comms[11] = new SMS("00478484777777", "00446999888888", 13, 10, 2021, "No internet connection today");
		comms[12] = new SMS("00478484777777", "00446999888888", 14, 10, 2021, "Gun Received from Rusty Knife");
		comms[13] = new SMS("00478484777777", "00446999888888", 15, 10, 2021, "Metro Attack ready");
		comms[14] = new SMS("00478484666666", "00446999888888", 16, 10, 2021, "Explosives downtown have been placed");
		
		//Creation of Registry object
		Registry registry = new Registry();
		
		registry.addSuspect(s1);
		registry.addSuspect(s2);
		registry.addSuspect(s3);
		registry.addSuspect(s4);
		
		for(int i=0; i<15; i++)
			registry.addCommunication(comms[i]);

		new FindSuspectGUI(registry);
	}

}

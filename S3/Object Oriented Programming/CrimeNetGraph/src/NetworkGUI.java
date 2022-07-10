import java.awt.Container;
import java.awt.Dimension;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

import javax.swing.*;

import edu.uci.ics.jung.algorithms.layout.*;
import edu.uci.ics.jung.graph.*;
import edu.uci.ics.jung.graph.util.EdgeType;
import edu.uci.ics.jung.visualization.BasicVisualizationServer;
import edu.uci.ics.jung.visualization.decorators.ToStringLabeller;
import edu.uci.ics.jung.algorithms.shortestpath.DistanceStatistics;

public class NetworkGUI extends JFrame {
	private JPanel panel;
	private JTextField diameterField;
	
	// Create a graph that accepts suspects
	private Graph<String, Set<Suspect>> graph = new UndirectedSparseMultigraph<>();
	private Layout <String, Set<Suspect>> layout;
	
	public NetworkGUI(Registry registry) {
		super("Suspects Network");
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		setSize(500, 450);
		setLocationRelativeTo(null);
		setResizable(false);
		
		// Add suspects as vertices
		for(Suspect suspect : registry.getSuspects()) {
			graph.addVertex(suspect.getName());
		}

		// Connect associated suspects
		for(Suspect suspect : registry.getSuspects()) {
			for(Suspect partner : suspect.getPartners()) {
				// If two vertices are already connected do not do anything
				// Otherwise the program throws an error
				if(!graph.containsEdge(new HashSet<Suspect>(Arrays.asList(suspect, partner)))) {
					graph.addEdge(new HashSet<Suspect>(Arrays.asList(suspect, partner)), suspect.getName(), partner.getName(), EdgeType.UNDIRECTED);
				}
			}
		}
		
		// Create panel that will contain the graph and the diameter text field
		panel = new JPanel();
		panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));
		
		// Create the graph layout
		layout = new CircleLayout<>(graph);
		layout.setSize(new Dimension(350, 350));
		BasicVisualizationServer <String, Set<Suspect>> v = new BasicVisualizationServer<>(layout);
		v.getRenderContext().setVertexLabelTransformer(new ToStringLabeller<String>());
		panel.add(v);
		
		// Create the text field and calculate diameter
		String diameterText = "Diameter = " + DistanceStatistics.diameter(graph);
		diameterField = new JTextField(diameterText, 20);
		panel.add(diameterField);
		
		// Add panel to content pane
		Container contentPane = getContentPane();
		contentPane.add(panel);
	}
}

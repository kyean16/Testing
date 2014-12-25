//Inspired and Learned from http://docs.oracle.com/javafx/2/get_started/form.htm#BABDDGEE
/*Author: Kevin Yean
 Date:December 24 2014

 Learning how to create a GUI using JavaFx with NetBeans. 
 Created a simple program that registers the username and password of a user, stores into an array
 and then sorts the array with the name of the username and then saves it into a text a file
 if clicked by the user.
 Very Safe.
 */
package hello;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javafx.geometry.Insets;
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextAreaBuilder;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.stage.WindowEvent;

public class Hello extends Application {

    boolean secondWindow = false;//Keeps track if the second window is closed.
    FileReader fr;
    BufferedReader bf;
    BufferedWriter output;
    
    @Override
    public void start(Stage primaryStage) {
        //File to be used for ssaving information 
         String path = "Hello.txt";
         try{ //Open Hello.txt if it exists
             fr = new FileReader (path);
             bf = new BufferedReader(fr);
         }
         catch (FileNotFoundException e){
            try { //Doesn't not exist therefore create a new text file.
                File file = new File("Hello.txt");
                output = new BufferedWriter(new FileWriter(file));
                output.write("List of People:\n\n");
                output.close();
                fr = new FileReader (path);
                bf = new BufferedReader(fr);
             }
            catch (IOException r){ //Catch random errors.
                System.out.println("Error Line 67");
            }
         } 
        //Creates the Grid Layout
        GridPane grid = new GridPane();
        grid.setAlignment(Pos.CENTER);
        grid.setHgap(10);
        grid.setVgap(10);
        grid.setPadding(new Insets(25, 25, 25, 25));
        // grid.setGridLinesVisible(true);

     //Title
        Text scenetitle = new Text("Enter your IMPORTANT information.");
        scenetitle.setFont(Font.font("Tahoma", FontWeight.NORMAL, 20));
        grid.add(scenetitle, 0, 0, 2, 1);

     // First Text with Texfield
        Label userName = new Label("User Name:");
        grid.add(userName, 0, 1);
        TextField userTextField = new TextField();
        grid.add(userTextField, 1, 1);

     //Second Text with Textfield
        Label pw = new Label("Password:");
        grid.add(pw, 0, 2);
        PasswordField pwBox = new PasswordField();
        grid.add(pwBox, 1, 2);

     //First Button with Event Handler
        Button btn = new Button("Confirm Information");
        HBox hbBtn = new HBox(10);
        hbBtn.setAlignment(Pos.BOTTOM_RIGHT);
        hbBtn.getChildren().add(btn);
        grid.add(hbBtn, 1, 4);
        final Text actiontarget = new Text();
        grid.add(actiontarget, 0, 6, 2, 2);

        btn.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent e) {
                actiontarget.setFill(Color.FIREBRICK);
                //If any of the two text field are empty
                if (userTextField.getLength() == 0 || pwBox.getLength() == 0) {
                    actiontarget.setText("Missing information!");
                } else { //If Both of the text field are not empty
                    actiontarget.setText("Information Saved");
                    try {
                        String filename= "hello.txt";
                        FileWriter fw = new FileWriter(filename,true); //the true will append the new data
                        fw.write("Username: " + userTextField.getText()+"\n" );//appends the string to the file
                        fw.write("Password: " + userTextField.getText()+"\n" );
                        fw.write("\n");
                        fw.close();
                    } catch (IOException ex) {
                        Logger.getLogger(Hello.class.getName()).log(Level.SEVERE, null, ex);
                    }
                    userTextField.setText("");
                    pwBox.setText("");
                }
            }
        });

    //Second Button with Event handler
        Button print = new Button("Retrieve Information");
        HBox hbPrint = new HBox(10);
        hbPrint.setAlignment(Pos.BOTTOM_LEFT);
        hbPrint.getChildren().add(print);
        grid.add(hbPrint, 0, 4);

        print.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent e) {

                actiontarget.setFill(Color.FIREBRICK);
                actiontarget.setText("Retrieving Information from Database");
             //Create second window
                if(!secondWindow) //If Second window is false meaning the window is open.
                {
                    secondWindow = true;
                    GridPane second = new GridPane();
                    //one.setGridLinesVisible(true);
                    second .setAlignment(Pos.CENTER);
                    second.setHgap(10);
                    second.setVgap(10);
                    second.setPadding(new Insets(25, 25, 25, 25));

                    //Title
                    Text title = new Text("List Of People");
                    title.setFont(Font.font("Tahoma", FontWeight.NORMAL, 20));
                    second.add(title, 0, 0);
                    
                    //Text Space
                     final TextArea information = TextAreaBuilder.create()
                            .prefWidth(400)
                            .wrapText(true)
                            .build();
                    information.setEditable(false);
                    information.setFont(Font.font("Times New Roman", FontWeight.NORMAL, 12));
                    second.add(information,0,1,2,2);
                    
                    try {
                        if(bf.ready())
                        {
                            String t;
                            String total ="";
                            while((t= bf.readLine())!=null)
                            {
                                total += t +"\n";
                            }
                            information.setText(total);
                            bf.close();
                        }
                    } 
                    catch (IOException ex) {
                        Logger.getLogger(Hello.class.getName()).log(Level.SEVERE, null, ex);
                    }
                    
                    //Update Button
                    Button update = new Button("Update");
                    HBox hbUpdate = new HBox(10);
                    hbUpdate.setAlignment(Pos.BOTTOM_CENTER);
                    hbUpdate.getChildren().add(update);
                    second.add(hbUpdate, 1, 4);
                    final Text secondActiontarget = new Text();
                    second.add(secondActiontarget, 0, 6, 2, 2);
                    
                    update.setOnAction(new EventHandler<ActionEvent>() {
                        @Override
                        public void handle(ActionEvent e) {
                            actiontarget.setFill(Color.FIREBRICK);
                            secondActiontarget.setText("Updating...");
                            try {
                                FileReader frTwo = new FileReader (path);
                                BufferedReader bfTwo = new BufferedReader(frTwo);
                                if (bfTwo.ready()) {
                                    String t;
                                    String total = "";
                                    while ((t = bfTwo.readLine()) != null) {
                                        total += t + "\n";
                                    }
                                    information.setText(total);
                                    bfTwo.close();
                                }
                            } catch (IOException ex) {
                                Logger.getLogger(Hello.class.getName()).log(Level.SEVERE, null, ex);
                            }
                            secondActiontarget.setText("");
                        }
                    });
                    
                    Stage newOne = new Stage();
                    Scene two = new Scene(second, 450, 275);
                    newOne.setX(200);
                    newOne.setY(200);
                    newOne.setScene(two);
                    newOne.setTitle("Totaly Not Copy of your information");
                    newOne.show();
                    actiontarget.setText("");
                    newOne.setOnCloseRequest(new EventHandler<WindowEvent>() {
                        public void handle(final WindowEvent e) {
                            secondWindow = false;
                        }
                    });
                }
                else
                {
                    actiontarget.setText("Window is already opened");
                }
                
                //Open up the file
               /* String s = getClass().getName();
                int i = s.lastIndexOf(".");
                if(i > -1) s = s.substring(i + 1);
                s = s + ".class";
                System.out.println("name " +s);
                Object testPath = this.getClass().getResource(s);
                System.out.println(testPath);*/
                
                    /*Process p = Runtime.getRuntime().exec("/Users/Keyean/Desktop/Hello/helladaso.txt");
                    p.waitFor();*/                  
                    //Desktop.getDesktop().edit(File "one");
               
            }
        });

        //Add grid to the the scene.
        Scene scene = new Scene(grid, 450, 275);
        primaryStage.setScene(scene);
        primaryStage.setTitle("Not Sketchy at all");
        primaryStage.setY(200);
        primaryStage.setX(600);
        primaryStage.show();
        
    }

    public static void main(String[] args) {
        launch(args);
    }

}

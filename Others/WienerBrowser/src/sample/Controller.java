package sample;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.TextField;
import javafx.scene.web.WebEngine;
import javafx.scene.web.WebView;

import javax.swing.*;
import java.net.URI;
import java.net.URISyntaxException;
import java.net.URL;
import java.util.ResourceBundle;

public class Controller implements Initializable {
    String htLink = "http://";

    @FXML
    TextField addressBar;

    @FXML
    WebView web;

    WebEngine engine;

    String adrsLink;

    public void  go(ActionEvent actionEvent){
        adrsLink = addressBar.getText().toString();

        //now check if the address is ok
        //else query google search

        if(!isValidURL(adrsLink)){
            String GOOGLE_SEARCH_URL = "https://www.google.com/search";
            String searchURL = GOOGLE_SEARCH_URL + "?q="+adrsLink;
            engine.load(searchURL);
        }else
             engine.load(htLink+adrsLink);
    }

    private boolean isValidURL(String uriString){
        try{
            URI uri = new URI(uriString);
            return true;
        }catch(URISyntaxException use){
            System.err.println(use.getMessage());
        }
        finally{
            return false;
        }
    }

    @FXML
    public void onEnter(ActionEvent actionEvent){
        go(actionEvent);
    }

    @FXML
    public void homeButton(ActionEvent actionEvent){
        engine.load(htLink+"www.google.com");
        addressBar.setText("www.google.com");

    }

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        engine = web.getEngine();
        engine.load(htLink+"www.google.com");
    }


}

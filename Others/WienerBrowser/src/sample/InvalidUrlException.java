package sample;

public class InvalidUrlException extends Exception {
    public InvalidUrlException(){
        super("The provided URL is not valid! ");
    }
    public InvalidUrlException(String str){
        super(str);
    }

}

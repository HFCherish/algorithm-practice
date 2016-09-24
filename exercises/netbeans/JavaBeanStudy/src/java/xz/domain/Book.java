/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package xz.domain;

/**
 *
 * @author Administrator
 */
public class Book {
    private Long id;
    private String name;
    private double price;
    private String author;
    private String bookConcern;
    private int counts;
    
    public Book(){}

    /**
     * @return the id
     */
    public Long getId() {
        return id;
    }

    /**
     * @param id the id to set
     */
    public void setId(Long id) {
        this.id = id;
    }

    /**
     * @return the name
     */
    public String getName() {
        return name;
    }

    /**
     * @param name the name to set
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * @return the price
     */
    public double getPrice() {
        return price;
    }

    /**
     * @param price the price to set
     */
    public void setPrice(double price) {
        this.price = price;
    }

    /**
     * @return the author
     */
    public String getAuthor() {
        return author;
    }

    /**
     * @param author the author to set
     */
    public void setAuthor(String author) {
        this.author = author;
    }

    /**
     * @return the bookConcern
     */
    public String getBookConcern() {
        return bookConcern;
    }

    /**
     * @param bookConcern the bookConcern to set
     */
    public void setBookConcern(String bookConcern) {
        this.bookConcern = bookConcern;
    }

    /**
     * @return the counts
     */
    public int getCounts() {
        return counts;
    }

    /**
     * @param counts the counts to set
     */
    public void setCounts(int counts) {
        this.counts = counts;
    }
}

import java.io.Serializable;

public class D_Object implements Serializable {

  byte [ ] data;
  String name;
  long size;
  int id;
  int partitions;

  public D_Object ( byte [ ] b, String n, long s, int p, int index ) {

    this.data = b;
    this.name = n;
    this.size = s;
    this.id = index;
    this.partitions = p;

  } // End constructor.

  public String getName ( ) {
    return this.name;
  }

  public byte [ ] getData ( ) {
    return this.data;
  }

  public long getSize ( ) {
    return this.size;
  }

  public int getPartitions ( ) {
    return this.partitions;
  }

  public String getObject ( ) {
    return "\n\tName: " + this.name + "\n\tBytes: " + this.data.length + "\n\tSize: " + this.size + "\n\tIndex: " + this.id + "\n";
  }
} // End class.

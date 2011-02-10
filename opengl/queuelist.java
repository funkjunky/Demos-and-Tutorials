
public class queuelist {
	
	listnode first;
	
	public queuelist()
	{first=null;}
	
	public void push(int a)
	{
		listnode temp = new listnode(a);
		
		listnode temp2 = first;
		first = temp;
		first.next = temp2;
	}
	
	public int front()
	{
		return (first==null)?null:first.datum;
	}
	
	public void pop()
	{
		if(!isempty())				// 'z' means end of list, whether you like it or not!
		{
		listnode temp = first.next;
		first = temp;}
	}
	
	public boolean isempty()
	{
		return (first==null);
	}
}

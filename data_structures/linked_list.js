class Node {
	constructor(data){
		  this.data = data
		  this.next = null;
		}
}

var node = new Node(1);
var node2 = new Node(2);
var node3 = new Node(3);
node.next = node2;
node2.next = node3;

function getLeng(x){
	  var count = 1;
	  var cur = x;
	  while(cur.next != null){
	  	   cur = cur.next;
	  	   count++
	  	}
	  	return count;
};
console.log(getLeng(node));

var
  preorder,inorder,postorder:string;

  procedure Solve(b1,e1,b2,e2:Integer); { in[b1..e1],post[b2..e2] }
  var j:integer;
  begin
    if b1>e1 then exit;
    j:=b1;
    while(inorder[j]<>postorder[e2]) do inc(j);
    preorder:=preorder+postorder[e2];
    Solve(b1,j-1,b2,b2+j-b1-1);
    Solve(j+1,e1,b2+j-b1,e2-1);    
  end;

  begin
    readln(inorder);    
    readln(postorder);
    Solve(1,length(inorder),1,length(postorder));
    writeln(preorder);
  end.

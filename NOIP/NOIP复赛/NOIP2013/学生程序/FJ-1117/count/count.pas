program count;
  var i,n,x,ans:longint;
begin
  assign(input,'count.in');
  reset(input);
  assign(output,'count.out');
  reset(output);  
  read(n,x);ans:=0;
  for i:=1 to n do
    begin
      if (i mod 10)=x then ans:=ans+1;
      if ((i mod 100)div 10)=x then ans:=ans+1;
      if ((i mod 1000)div 100)=x then ans:=ans+1;
      if ((i mod 10000)div 1000)=x then ans:=ans+1;
      if ((i mod 100000)div 10000)=x then ans:=ans+1;
      if ((i mod 1000000)div 100000)=x then ans:=ans+1;
      if (i div 1000000)=x then ans:=ans+1;
    end;
  write(ans);
  close(input);
  close(output);
end.  
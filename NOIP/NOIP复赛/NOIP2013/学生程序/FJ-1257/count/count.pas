program count;
 var n,x,init,i,j,len:longint;ans,ans1,ans2:string;
 begin
 assign(input,'count.in');reset(input);
 assign(output,'count.out');rewrite(output);
 readln(n,x);str(x,ans1);
 for i:=1 to n do
  begin
  str(i,ans);
  len:=length(ans);
  for j:=1 to len do
  if ans1=ans[j] then inc(init);
  end;
  write(init);
  close(input);close(output);
  end.
var
  n,m,i,j,k,t,ans,head,tail,ko:longint;
  h:array[0..100001] of longint;
  bo:array[0..100001] of boolean;

begin
assign(input,'flower.in');  reset(input);
assign(output,'flower.out'); rewrite(output);
  readln(n);
  for i:=1 to n do
    begin
      read(h[i]);
      bo[i]:=false;
    end;




  head:=1; tail:=1;
  bo[1]:=true;
  while tail<=n do
   begin
     inc(tail);
     if h[tail]>=h[head] then
      begin
        bo[head]:=false;
        head:=tail;
        bo[head]:=true;
      end
     else
       begin
         k:=tail+1;
         while (h[k]<=h[tail]) and (k<=n) do inc(k);
         if k>=n+1 then continue;
         tail:=k-1;
         bo[tail]:=true;
         head:=k;
         bo[head]:=true;
         tail:=head;
       end;


   end;

  for i:=1 to n do
    if bo[i]=true then
      begin
        inc(ans);
        if ans=1 then ko:=i;
      end;
  if (bo[1]=false) and (h[1]<h[ko]) then inc(ans);
  writeln(ans);



close(input); close(output);
end.

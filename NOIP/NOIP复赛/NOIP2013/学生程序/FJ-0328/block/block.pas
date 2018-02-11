var n,min,maxh,st,head,tail,step,i,j,l,h,t:longint;
    a:array[1..100000]of longint;
begin
 assign(input,'block.in'); reset(input);
 assign(output,'block.out'); rewrite(output);
 min:=maxlongint;
 readln(n);
 for i:=1 to n do
  begin
   read(a[i]);
   if (a[i]>0) and (a[i]<min) then min:=a[i];
  end;
 step:=min;
 for i:=1 to n do
  begin
   if (a[i]=0) and (i>1) and (i<n) then step:=step+min;
   if a[i]>0 then a[i]:=a[i]-min;
  end;
 l:=n;
 for i:=1 to n do if a[i]=0 then dec(l);
 head:=1; tail:=1;
 while l>0 do
  begin
   while a[head]=0 do begin inc(head); inc(tail); end;
   maxh:=a[head];
   while (tail<=n) and (a[tail]>0) do
    begin
     inc(tail);
     if maxh<a[tail] then maxh:=a[tail];
    end;
   tail:=tail-1;
   for i:=head to tail do a[i]:=0;
   dec(l,tail-head+1);
   inc(step,maxh);
   inc(tail); head:=tail;
  end;
 writeln(step);
 close(input); close(output);
end.






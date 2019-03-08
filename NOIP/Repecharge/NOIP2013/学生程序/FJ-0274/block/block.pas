program block;
 var n,i,ans:longint;
     a:array[1..100000] of longint;
procedure go(l,r:longint);
 var i,min,x:longint;
     f:array[1..100000] of longint;
 begin
   x:=l;min:=maxlongint;
   for i:=l to r do if a[i]<min then min:=a[i];
    if min=0 then exit else ans:=ans+min;
   for i:=l to r+1 do
    begin
     if i<=r then a[i]:=a[i]-min;
     if a[i]=0 then begin
      while(a[x]=0)and(x<=r+1) do inc(x);
       if x<=i-1 then begin
        go(x,i-1);x:=i+1;
                      end;
                    end;
    end;
 end;
 begin
  assign(input,'block.in');reset(input);
  assign(output,'block.out');rewrite(output);
  fillchar(a,sizeof(a),0);
   readln(n);for i:=1 to n do read(a[i]);
    ans:=0;go(1,n);
     write(ans);
  close(input);close(output);
 end.
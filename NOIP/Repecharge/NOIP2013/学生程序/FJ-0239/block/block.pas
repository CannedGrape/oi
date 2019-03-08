var n,i,j,min,t,ans,s,p:longint;
    b:boolean;
    a:array[0..100000]of longint;
begin
  assign(input,'block.in');
  assign(output,'block.out');
  reset(input);
  rewrite(output);
  readln(n);
  min:=maxlongint;
  for i:=1 to n do
    begin
      read(a[i]);
      s:=s+a[i];
      if a[i]<min then min:=a[i];
    end;
  t:=min;
  a[0]:=0;
  p:=n+1;
  while s>0 do
    begin
      min:=maxlongint;
      for i:=1 to p do
        if a[i]=0 then
          begin
            if (a[i-1]<>0)or(b) then
              ans:=ans+t;
            b:=false;
          end
        else
          begin
            a[i]:=a[i]-t;
            s:=s-t;
            if (a[i]<min)and(a[i]<>0) then min:=a[i];
            b:=true;p:=i+1;
          end;
      t:=min;
    end;
  writeln(ans);
  close(input);
  close(output);
end.
{rp++;rp:=maxlongint;orz WJMZBMR;orz JSZKC;}
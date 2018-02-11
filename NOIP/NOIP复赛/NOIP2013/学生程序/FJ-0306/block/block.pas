program ex_1;
var a,b,c:array[0..100001]of longint;
    n,i,j,k,ans,p,t:longint;xx:boolean;
begin
  assign(input,'block.in');reset(input);
  read(n);
  p:=0;
  for i:=1 to n do
    begin
      read(a[i]);
      if a[i]=0 then inc(p);
    end;
  close(input);
  repeat
    xx:=true;
    for i:=1 to n do
      begin
        if b[i]<>a[i] then
          begin
            inc(b[i]);if b[i]=a[i] then inc(p);
            if xx then begin inc(t);xx:=false;end;
          end
        else xx:=true;
      end;
  until p=n;
  assign(output,'block.out');rewrite(output);
  write(t);
  close(output);
end.


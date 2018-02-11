program p01_4(input,output);{◊∞œ‰Œ Ã‚  Zhuang_Xiang_Wen_Ti}
const maxn=31;maxv=20000;
type arr=array[0..maxn] of integer;
var w,a:arr;
    rem,r,v,n,i:integer;

procedure sort(var w:arr);
var i,j,temp:integer;
begin
    for i:=1 to n-1 do
      for j:=i+1 to n do
         if w[j]<w[i] then begin temp:=w[i];w[i]:=w[j];w[j]:=temp;end;
end;


begin
    assign(input,'pack.in');
    reset(input);
    readln(v,n);
    for i:=1 to n do begin readln(w[i]);a[i]:=0;end;
    close(input);
    r:=v;rem:=v;
    sort(w);
    assign(output,'pack.out');
    rewrite(output);
    i:=1;
    while true do begin
      if (i<=n) and (rem>=w[i]) then begin
           a[i]:=1;
           rem:=rem-w[i];
           if rem=0 then begin writeln(0);close(output);halt;end;
           if rem<r then r:=rem;
         end
      else
        begin
           i:=i-1;
           while (i>0) and (a[i]=0) do i:=i-1;
           if i=0 then begin writeln(r);close(output);halt;end;
           a[i]:=0;
           rem:=rem+w[i];
           while (i<n) and (w[i]=w[i+1]) do i:=i+1;
        end;
      i:=i+1;
   end;
end.


var n,i,j,k,ans:longint;a,b,c:array[1..100001]of longint;
begin
assign(input,'match.in');
reset(input);
assign(output,'match.out');
rewrite(output);
    readln(n);
    for i:=1 to n do read(a[i]);
    readln;
    for i:=1 to n do  begin read(b[i]);c[i]:=b[i];end;
    for i:=1 to n-1 do
        for j:=i+1 to n do begin
            if a[i]>a[j] then begin
                 k:=a[i];a[i]:=a[j];a[j]:=k;
                 k:=c[i];c[i]:=c[j];c[j]:=k;
            end;
            if b[i]>b[j] then begin
                 k:=b[i];b[i]:=b[j];b[j]:=k;
            end;
            end;
    ans:=0;

    for i:=1 to n-1 do
      begin

        if c[i]<>b[i] then begin ans:=ans+1;
             if ans>=99999997 then ans:=ans mod 99999997;
                 for j:=i+1 to n do
                        begin  if c[j]=b[i] then begin
                                  k:=c[i];c[i]:=c[j];c[j]:=k;break;end;
                          end;
        end;

      end;

   writeln(ans);
   close(input);
   close(output);
   end.

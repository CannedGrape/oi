program number;
var n,p,max,max1,max2,i,j,z:longint;
    a:array[1..1000000] of longint;
begin
  assign(input,'number.in');
  assign(output,'number.out');
  reset(input);
  rewrite(output);
    readln(n,p);
    for i:=1 to n-1 do
      begin
        read(a[i]);
        z:=0;
        max:=-maxlongint;
        for j:=1 to i do
          begin
            z:=z+a[j];
            if z>max then max:=z;
            if z<0 then z:=0;
          end;
        if i=1 then begin max1:=a[i]+a[i]; max2:=a[i]; end
          else
            begin
              if max1+max>max2 then begin max2:=max1+max; max1:=max2; end
                else if max+max1>max1 then max1:=max+max1;
            end;
      end;
    write(max2 mod p);
  close(input);
  close(output);
end.

program Number;

var a,b:array[0..1000001] of int64;
    i,n,m:longint;
    t:int64;

    procedure Double_M(k:longint);
    var j,t:longint;
    begin
      b[k]:=b[k-1];t:=0;
      for j:=1 to k do
        if t+a[j]>0 then t:=t+a[j]
          else t:=0;
      if (t>0) and (t>b[k]) then b[k]:=t;
    end;

begin
  assign(input,'number.in');reset(input);
  assign(output,'number.out');rewrite(output);

  readln(n,m);
  for i:=1 to n do begin
    read(a[i]);a[i]:=a[i] mod m;
  end;

  b[1]:=a[1];
  for i:=2 to n do Double_M(i);
  fillchar(a,sizeof(a),0);
  t:=b[1];
  for i:=1 to n do begin
    a[i]:=t;
    if t<a[i]+b[i] then t:=(a[i]+b[i]) mod m;
  end;

  writeln(a[n]);

  close(input);close(output);
end.

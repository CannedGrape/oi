var max,d,e,f,g,h,q,m,n,k,l,t1,t2:int64; i,j:longint;
    c1,c2:array[0..300000] of int64;
    b,a1,a2,a3:array[1..500000] of int64;

    procedure try(x:longint);
     var k,j:longint;
      begin
       if x=c2[i] then begin if max=9999990 then write('-1')
        else writeln(max); exit; end;

       for k:=1 to n do
        if (a1[k]=x) and (b[k]=0)  then begin b[k]:=1;
         if max>a3[k] then max:=a3[k];  try(a2[k]);b[k]:=0;  end;

      end;


  begin   assign(input,'truck.in'); reset(input);
          assign(output,'truck.out'); rewrite(output);
  max:=9999990; l:=0;   fillchar(b,sizeof(b),0);
   readln(n,m);
    for i:=1 to m do
     readln(a1[i],a2[i],a3[i]);
   readln(q);
     for i:=1 to q do readln(c1[i],c2[i]);
      for i:=1 to q do begin  max:=9999990; try(c1[i]); end;
       close(input); close(output);
    end.






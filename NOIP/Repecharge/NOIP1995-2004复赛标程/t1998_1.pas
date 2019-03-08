program t1998_1;
var upa1,upb1,upa2,upb2,downa,downb:integer;
    lefta,leftb,xa,xb:integer;
    i,n,a,m,x,y:integer;

begin
    assign(input,'station.in');
    reset(input);
    readln(a,n,m,x);
    close(input);
    assign(output,'station.out');
    rewrite(output);
    upa1:=1;upb1:=0;
    upa2:=0;upb2:=1;
    downa:=0;downb:=1;
    lefta:=1;leftb:=0;
    for i:=3 to n-1 do begin
        downa:=upa2;{Xia Che Ren Shu}
        downb:=upb2;
        upa2:=upa2+upa1;{Sha Che Ren Shu}
        upb2:=upb2+upb1;
        upa1:=downa;
        upb1:=downb;
        lefta:=lefta+upa2-downa;{Ben Zhan Ren Shu}
        leftb:=leftb+upb2-downb;
        if i=x then  {X Zhan Ren Shu}
            begin xa:=lefta;xb:=leftb;end;
    end;
    y:=(m-lefta*a) div leftb;
    writeln(xa*a+xb*y);
    close(output);
end.

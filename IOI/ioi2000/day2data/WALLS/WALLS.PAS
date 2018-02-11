{$A+,B-,D-,E+,F-,G+,I-,L-,N+,O-,P-,Q-,R-,S-,T-,V+,X+,Y-}
{$M 65520,0,655360}

program Walls;

{
 Task Name : Walls
 Round     : Day 2
 Type      : Batch Type
 Programmer: Qi, Xin
 Date      : Sep 19, 2000
}

const Mmax = 200; {maximal number of areas}
      Nmax = 250; {maximal number of towns}
      Imax = 50;  {maximal number of sides of a polygon}
      Lmax = 30;  {maximal number of members}

var
    m: integer;   {number of areas}
    n: integer;   {number of towns}
    l: integer;   {number of members}
    inTown: array [1..Nmax] of 1..Lmax;
                  {inTown[i] keeps the No. of member who lives in Town #i,
                   and should be 0 when there is no member}
    roundArea: array [1..Mmax, 0..Imax+1] of 0..Nmax;
                  {roundArea[i] contains the numbers of the walls
                   clockwisely around the area #i, in which:
                     roundArea[i,0] holds the number of the walls, and
                     roundArea[i,roundArea[i,0]+1]=roundArea[i,1]}
    viaWalls: array [1..Mmax, 1..Mmax] of byte;
                  {viaWalls[i,j] means the least walls that should be passed
                   when traveling from area i to area j}
    best: 0..Mmax;{the best aggregating area}
    keep: word;   {the least walls that should be passed}

procedure initialize;{Get in the input data}
  var
      i, j, p, q: integer;
      f: text;    {input file}

  begin
    assign(f, 'walls.in');
    reset(f);
    readln(f, m);
    readln(f, n);
    readln(f, l);
    fillchar(inTown, sizeof(inTown), 0);
    for i:= 1 to l do begin
      read(f, j);
      inTown[j]:= i;
    end;
    readln(f);
    fillchar(viaWalls, sizeof(viaWalls), 255);
    for i:= 1 to m do viaWalls[i, i]:= 0;
    for i:= 1 to m do begin
      readln(f, roundArea[i, 0]);
      for j:= 1 to roundArea[i, 0] do read(f, roundArea[i, j]);
      readln(f);
      roundArea[i, roundArea[i, 0]+1]:= roundArea[i, 1];
      for j:= 1 to roundArea[i, 0] do
        for p:= 1 to i-1 do
          for q:= 1 to roundArea[p, 0] do
            if (roundArea[p, q+1]=roundArea[i, j])
            and (roundArea[p, q]=roundArea[i, j+1]) then begin
              viaWalls[i, p]:= 1; viaWalls[p, i]:= 1;
              break;
            end;
    end;
    close(f);
  end;{initialize}

procedure deal;{Solve the problem}
  var
      i, j, k: integer;
      ds: array [1..Lmax] of byte;
                  {ds[i]: number of walls that member #i should pass on the
                   way to the current area}
      tmp: word;

  begin
    for i:= 1 to m do
      for j:= 1 to m do
        for k:= 1 to m do
          if (viaWalls[j, i]+viaWalls[i, k]<viaWalls[j, k]) then
            viaWalls[j, k]:= viaWalls[j, i]+viaWalls[i, k];

    keep:= 65535;
    for i:= 1 to m do begin
      fillchar(ds, sizeof(ds), 255);
      for j:= 1 to m do
        for k:= 1 to roundArea[j, 0] do
          if (inTown[roundArea[j, k]]>0)
          and (ds[inTown[roundArea[j, k]]]>viaWalls[i, j]) then
            ds[inTown[roundArea[j, k]]]:= viaWalls[i, j];
      tmp:= 0;
      for j:= 1 to l do inc(tmp, ds[j]);
      if (tmp<keep) then begin
        keep:= tmp;
        best:= i;
      end;
    end;
  end;{deal}

procedure printout;{Print out the result}
  var
      f: text;    {output file}

  begin
    assign(f, 'walls.out');
    rewrite(f);
    writeln(f, keep);
    writeln(f, best);
    close(f);
  end;{printout}

begin{main}
  initialize;
  deal;
  printout;
end.
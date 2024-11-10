run:
	g++ test.cpp -o test -O2
	./test
clean:
	rm test
report: report.tex
	latex report.tex
	dvipdf report.dvi
	rm report.log
	rm report.aux
	rm report.dvi

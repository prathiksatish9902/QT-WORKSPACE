#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QFont>
#include <QFontDatabase>

class FontFallbackWidget : public QWidget {
protected:
    void paintEvent(QPaintEvent *) override {
        QPainter painter(this);

        // Primary font with ss03 feature
        QFont primaryFont("Noto Sans", 16);
        primaryFont.setFeature("ss03", 1); // Enable stylistic set 03 for Latin characters
        painter.setFont(primaryFont);

        // Render Latin text
        QString latinText = "Hello";
        painter.drawText(50, 50, latinText);

        // Switch to fallback font for CJK characters (no ss03 feature)
        QFont fallbackFont("Noto Sans CJK SC", 16);
        painter.setFont(fallbackFont);

        // Render CJK text
        QString cjkText = "世界";
        painter.drawText(50, 80, cjkText);
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Add fallback font for CJK characters
    QFontDatabase::addApplicationFont("/path/to/NotoSansCJKsc-Regular.ttf");

    FontFallbackWidget widget;
    widget.setWindowTitle("Font Fallback Solution Example");
    widget.resize(300, 150);
    widget.show();

    return app.exec();
}

/*
\note When font fallback occurs (e.g., when rendering characters not supported
by the primary font, such as CJK characters in a Latin-based font), the features
set via setFeature() are applied only to the primary font and not to the fallback
font. Fallback fonts are selected based on glyph availability and may not support
the same OpenType features, which could result in different rendering behavior.
For example, enabling the \c ss03 feature to alter Latin glyphs in the primary font
will not affect a fallback font used for CJK characters, which may have a different
or no implementation of \c ss03. To ensure consistent rendering across scripts,
consider explicitly managing fallback fonts using QFontDatabase::addApplicationFont()
or setting separate QFont objects for different scripts. For example, you can create one
QFont with features for Latin text and another without features for CJK text, then apply
them selectively when rendering.
*/



/*!
    \note During font fallback (e.g., for CJK characters in a Latin-based font),
features set via setFeature() apply only to the primary font, not fallback fonts.
Fallback fonts, chosen for glyph availability, may not support the same OpenType features,
 leading to inconsistent rendering. For example, enabling \c ss03 for Latin glyphs won’t
 affect a CJK fallback font. For consistent rendering, manage fallback fonts explicitly
using QFontDatabase::addApplicationFont() or use separate QFont objects for different scripts.
*/





/*
\note During font fallback (e.g., for CJK characters in a Latin-based font),
features set via setFeature() apply only to the primary font, not fallback fonts.
Fallback fonts, chosen for glyph availability, may not support the same OpenType features,
leading to inconsistent rendering. For consistent rendering, manage fallback fonts explicitly
using QFontDatabase::addApplicationFont() or use separate QFont objects for different scripts.
*/





/*
 During font fallback (e.g., for CJK characters in a Latin-based font),
features set via setFeature() apply only to the primary font, not fallback fonts,
 which are chosen based on glyph availability and may not support the same OpenType features,
 potentially causing inconsistent rendering. To ensure consistent rendering across scripts,
 use QFontDatabase::addApplicationFont() to manage fallback fonts or apply separate QFont objects for different scripts.
*/

/*
 \note By default, Qt enables or disables certain font features based on other font properties.
For example, the \c kern feature is enabled or disabled depending on the kerning() property of the
 QFont, and ligature features (\c liga, \c clig, \c dlig, \c hlig) are disabled if letterSpacing()
is applied in writing systems where ligatures are cosmetic. For writing systems where ligatures are required,
these features remain in their default state. Values set using setFeature() override these defaults;
for instance, setting \c kern to 1 forces kerning on, even if kerning() is false, while setting it to 0 disables it.
 During font fallback (e.g., for CJK characters in a Latin-based font),
features set via setFeature() apply only to the primary font, not fallback fonts,
which are chosen based on glyph availability and may not support the same OpenType features,
 potentially causing inconsistent rendering. To ensure consistent rendering across scripts,
use QFontDatabase::addApplicationFont() to manage fallback fonts or apply separate QFont objects for different scripts.
To reset a feature to its default behavior, use unsetFeature().
*/






/*!
    \fn void QFont::setFeature(QFont::Tag tag, quint32 value)
    {
    This is an overloaded function.

    Applies an integer \a value to the typographical feature specified by \a tag when shaping the text.
This provides advanced access to the font shaping process, allowing access to font features that are otherwise
not covered in the API. The feature is specified by a \a tag, which is typically encoded from the four-character feature name in the font feature map.
 During font fallback (e.g., for CJK characters in a Latin-based font),
features set via setFeature() apply only to the primary font, not fallback fonts,
 which are chosen based on glyph availability and may not support the same OpenType features,
potentially causing inconsistent rendering. To ensure consistent rendering across scripts,
 use QFontDatabase::addApplicationFont() to manage fallback fonts or apply separate QFont objects for different scripts.

    This integer \a value passed along with the \a tag in most cases represents a boolean value: A zero value means the feature is disabled, and a non-zero value means it is enabled. For certain font features, however, it may have other interpretations. For example, when applied to the \c salt feature, the \a value is an index that specifies the stylistic alternative to use.

    For example, the \c frac font feature will convert diagonal fractions separated with a slash (such as 1/2) with a different representation. Typically, this will involve baking the full fraction into a single character width (such as ½).

    If a font supports the \c frac feature, then it can be enabled in the shaper by setting features["frac"] = 1 in the font feature map.

    \note By default, Qt enables or disables certain font features based on other font properties. For example, the \c kern feature is enabled or disabled depending on the kerning() property of the QFont, and ligature features (\c liga, \c clig, \c dlig, \c hlig) are disabled if letterSpacing() is applied in writing systems where ligatures are cosmetic. For writing systems where ligatures are required, these features remain in their default state. Values set using setFeature() override these defaults; for instance, setting \c kern to 1 forces kerning on, even if kerning() is false, while setting it to 0 disables it. To reset a feature to its default behavior, use unsetFeature().

    \sa unsetFeature(), featureTags(), featureValue(), QFontDatabase
*/

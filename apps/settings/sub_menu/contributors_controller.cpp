#include "contributors_controller.h"
#include <assert.h>

namespace Settings {

ContributorsController::ContributorsController(Responder * parentResponder) :
  GenericSubController(parentResponder)
{
  for (int i = 0; i < k_totalNumberOfCell; i++) {
    m_cells[i].setMessageFont(KDFont::LargeFont);
    m_cells[i].setAccessoryFont(KDFont::SmallFont);
    m_cells[i].setAccessoryTextColor(Palette::SecondaryText);
  }
}

bool ContributorsController::handleEvent(Ion::Events::Event event) {
  return GenericSubController::handleEvent(event);
}

HighlightCell * ContributorsController::reusableCell(int index, int type) {
  assert(type == 0);
  assert(index >= 0 && index < k_totalNumberOfCell);
  return &m_cells[index];
}

int ContributorsController::reusableCellCount(int type) {
  assert(type == 0);
  return k_totalNumberOfCell;
}

constexpr static int s_numberOfDevelopers = 4;
constexpr static int s_numberOfSigmaDevelopers = 2;
constexpr static int s_numberOfUpsilonDevelopers = 1;
constexpr static I18n::Message s_developersUsernames[s_numberOfDevelopers] = {
  I18n::Message::PAxelMontlahuc,
  I18n::Message::PAndrei,
  I18n::Message::PUpsilonTeam,
  I18n::Message::POmegaTeam
};

void ContributorsController::willDisplayCellForIndex(HighlightCell * cell, int index) {
  MessageTableCellWithBuffer * myTextCell = (MessageTableCellWithBuffer *)cell;
  myTextCell->setAccessoryText(I18n::translate(s_developersUsernames[index]));
  if (index < s_numberOfSigmaDevelopers) {
    myTextCell->setTextColor(KDColor::RGB24(0x4ac3a5));
  } else if (index < (s_numberOfSigmaDevelopers + s_numberOfUpsilonDevelopers)) {
    myTextCell->setTextColor(KDColor::RGB24(0x5e81ac));
  } else {
    myTextCell->setTextColor(KDColor::RGB24(0xc53431));
  }
  myTextCell->setAccessoryTextColor(Palette::SecondaryText);
  GenericSubController::willDisplayCellForIndex(cell, index);
}

}
